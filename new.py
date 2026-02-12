import matplotlib.pyplot as plt

# Data
projects = [
    "Long-Term IoT-Based Maternal Monitoring\n(2021)",
    "IoT-Enabled Wearable Device\n(2025)",
    "Comprehensive Monitoring System\n(2024)",
    "IoT in Pregnancy Care Coordination\n(2023)",
    "Smart Pregnancy Monitoring Kit"
]
accuracy = [85, 88, 83, 88, 94]

# Plot
plt.figure(figsize=(10,6))
bars = plt.bar(projects, accuracy, color='#D19C34')

# Add percentages on top of bars
for bar, acc in zip(bars, accuracy):
    plt.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 1, f'{acc}%', ha='center', va='bottom', fontsize=12)

# Labels and title
plt.ylabel("Detection / System Efficiency (%)", fontsize=12)
plt.xlabel("Research Projects", fontsize=12)
plt.title("Comparison of IoT-Based Maternal Monitoring Systems", fontsize=14)
plt.ylim(0, 100)
plt.grid(axis='y', linestyle='--', alpha=0.7)

plt.tight_layout()
plt.show()
