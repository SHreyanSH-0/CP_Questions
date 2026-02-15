# Create simulator object
set ns [new Simulator]

# Define trace and NAM files
set tracefile [open stopwait.tr w]
$ns trace-all $tracefile

set namfile [open stopwait.nam w]
$ns namtrace-all $namfile

# Create nodes
set n0 [$ns node]   ;# Sender
set n1 [$ns node]   ;# Receiver

# Create duplex link
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

# Define TCP agent (Stop-and-Wait behavior)
set tcp [new Agent/TCP]
$tcp set window_ 1        ;# Stop-and-Wait (window size = 1)
$ns attach-agent $n0 $tcp

# Define TCP Sink (Receiver)
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink

# Connect sender and receiver
$ns connect $tcp $sink

# Create FTP application
set ftp [new Application/FTP]
$ftp attach-agent $tcp

# Start and stop FTP
$ns at 0.5 "$ftp start"
$ns at 4.5 "$ftp stop"

# Finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam stopwait.nam &
    exit 0
}

# End simulation
$ns at 5.0 "finish"

# Run simulation
$ns run