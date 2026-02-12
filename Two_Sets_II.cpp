import serial
import requests
import time
import re

# Arduino port
ser = serial.Serial('COM5', 9600, timeout=1)  # Update COM if needed

# Pushbullet API key
API_KEY = "o.IFcRm0dbiUIzDlekNefsFdMRIpgeUvyx"

def send_push(message):
    """Send a Pushbullet notification"""
    data = {
        "type": "note",
        "title": "Arduino Sensor Alert",
        "body": message
    }
    try:
        requests.post(
            "https://api.pushbullet.com/v2/pushes",
            json=data,
            headers={"Access-Token": API_KEY}
        )
    except Exception as e:
        print("Pushbullet error:", e)

print("Listening to Arduino... Press Ctrl+C to stop.")

last_push_time = 0
push_interval = 60  # seconds between normal readings
display_interval = 5  # seconds between console updates
last_display_time = 0
latest_line = ""

# alert keywords (match Arduino exactly, case-insensitive check)
alert_keywords = ["Gas Alert", "FALL DETECTED", "Stress Alert", "Pulse Alert"]

# Debounce for repeated alerts (seconds)
debounce_seconds = 10
last_alert_time = 0
last_alert_text = ""

# helper to parse numeric fields from a serial line
def parse_values(line):
    # returns dict with possible keys: MQ, Skin, BPM, Acc
    values = {}
    try:
        m = re.search(r"MQ:\s*([0-9]+(?:\.[0-9]+)?)", line, re.IGNORECASE)
        if m: values['MQ'] = float(m.group(1))
        m = re.search(r"Skin:\s*([0-9]+(?:\.[0-9]+)?)", line, re.IGNORECASE)
        if m: values['Skin'] = float(m.group(1))
        m = re.search(r"BPM:\s*([0-9]+(?:\.[0-9]+)?)", line, re.IGNORECASE)
        if m: values['BPM'] = float(m.group(1))
        m = re.search(r"Acc:\s*([0-9]+(?:\.[0-9]+)?)", line, re.IGNORECASE)
        if m: values['Acc'] = float(m.group(1))
    except Exception:
        pass
    return values

def check_and_send_alert_from_status(status_text, full_line):
    global last_alert_time, last_alert_text
    status_norm = status_text.strip()
    if any(k.lower() in status_norm.lower() for k in alert_keywords):
        now = time.time()
        # send if changed or debounce expired
        if status_norm != last_alert_text or (now - last_alert_time) > debounce_seconds:
            send_push(f"ALERT: {status_norm}\n{full_line}")
            last_alert_text = status_norm
            last_alert_time = now
            print("Sent alert:", status_norm)
            return True
    return False

def check_and_send_alert_from_values(vals, full_line):
    # Fallback detection using thresholds from Arduino
    global last_alert_time, last_alert_text
    now = time.time()
    detected = None
    if 'MQ' in vals and vals['MQ'] > 250:
        detected = "Gas Alert"
    elif 'Acc' in vals and vals['Acc'] < 5.0:
        detected = "FALL DETECTED"
    elif 'Skin' in vals and vals['Skin'] > 600:
        detected = "Stress Alert"
    elif 'BPM' in vals and (vals['BPM'] > 0) and (vals['BPM'] < 60 or vals['BPM'] > 120):
        detected = "Pulse Alert"

    if detected:
        if detected != last_alert_text or (now - last_alert_time) > debounce_seconds:
            send_push(f"ALERT: {detected}\n{full_line}")
            last_alert_text = detected
            last_alert_time = now
            print("Sent alert (from values):", detected)
            return True
    return False

try:
    while True:
        try:
            line = ser.readline().decode(errors='ignore').strip()
        except Exception as e:
            print("Serial read error:", e)
            line = ""

        if line:
            latest_line = line  # store latest reading

            # Primary: look for STATUS: ...
            if "STATUS:" in line.upper():
                # find status text after STATUS:
                try:
                    # case-insensitive split
                    idx = line.upper().index("STATUS:")
                    status_text = line[idx + len("STATUS:"):].strip()
                except Exception:
                    status_text = line.split("STATUS:")[-1].strip()
                check_and_send_alert_from_status(status_text, line)
            else:
                # Fallback: parse numeric values and detect alerts
                vals = parse_values(line)
                if vals:
                    check_and_send_alert_from_values(vals, line)

        current_time = time.time()

        # Update command prompt every 5 seconds
        if current_time - last_display_time > display_interval and latest_line:
            print(latest_line)
            last_display_time = current_time

        # Send normal readings every 1 minute
        if current_time - last_push_time > push_interval and latest_line:
            send_push(latest_line)
            last_push_time = current_time

        time.sleep(0.01)  # tiny sleep to reduce CPU spin

except KeyboardInterrupt:
    print("Stopped by user")
except Exception as e:
    print("Fatal error:", e)