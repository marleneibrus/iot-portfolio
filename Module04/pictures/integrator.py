import iotknit
import threading
from temp import publish_temperature
from ac import display_ac_status, subscribe_to_temperature

# Initialize MQTT broker connection
iotknit.init("192.168.14.1")  # Use a MQTT broker on localhost

# Run the temperature simulator and AC simulator in separate threads
temp_thread = threading.Thread(target=publish_temperature)
temp_thread.daemon = True
temp_thread.start()

ac_thread = threading.Thread(target=display_ac_status)
ac_thread.daemon = True
ac_thread.start()

# Subscribe to temperature updates for AC control
subscribe_to_temperature()

# Keep the main thread running
iotknit.run()  # Or use a while loop like: while True: iotknit.process()
