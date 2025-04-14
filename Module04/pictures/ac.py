import iotknit
import time

# Global variable to keep track of the AC state
ac_state = "off"  # Default state is off

# Function to handle temperature updates and control the AC
def tempCallback(msg):
    global ac_state  # Access the global variable

    print("Received temperature:", msg)
    try:
        t = float(msg)  # Convert received temperature to a float
    except ValueError:
        return

    # Control AC based on the temperature
    if t >= 25:
        ac_state = "on"  # Set AC state to on
        switch.publish("set", "on")  # Publish "on" to the topic
        print("Sending: [AC ON]")
    else:
        ac_state = "off"  # Set AC state to off
        switch.publish("set", "off")  # Publish "off" to the topic
        print("Sending: [AC OFF]")

# Function to display AC status every second
def display_ac_status():
    global ac_state  # Access the global variable

    while True:
        # Print the current AC state
        if ac_state == "on":
            print("AC is turned ON")
        else:
            print("AC is turned OFF")
        time.sleep(1)  # Display AC status every second

# Function to subscribe to the temperature topic and trigger actions based on temperature
def subscribe_to_temperature():
    iotknit.prefix("temp-measure")
    button1 = iotknit.subscriber("temp1")  # Subscribe to the temp1 topic
    button1.subscribe_change(callback=tempCallback)

