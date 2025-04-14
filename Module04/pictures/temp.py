import math
import time
import iotknit

# Function to simulate temperature
def simulate_temperature():
    # Use a sine wave to simulate gradual temperature changes
    temperature = 20 + 10 * math.sin(time.time() / 10)  # Temperature oscillates between 15 and 25°C
    return round(temperature, 2)

# Function to publish temperature to a specific MQTT topic
def publish_temperature():
    # Create a publisher for the temperature simulator
    iotknit.prefix("temp-measure")  # all sensors below are prefixed with /temp-measure
    temp_publisher = iotknit.publisher("temp1")  # create a publisher for temp1

    while True:
        # Generate a simulated temperature value
        temp = simulate_temperature()
        # Publish the simulated temperature to the topic
        temp_publisher.publish("measure", str(temp))
        print(f"Publishing temperature: {temp}°C")
        time.sleep(1)  # Wait for 1 second before publishing the next value
