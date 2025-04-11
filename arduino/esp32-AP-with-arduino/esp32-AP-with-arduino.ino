#include <WiFi.h>
#include <WebServer.h>

// WiFi Access Point Configuration
const char *SSID = "Quadruped_Robot";
const char *PASSWORD = "12345678";

// Commands (13 total actions)
enum RobotCommands
{
    CMD_STOP = 0,
    CMD_FORWARD = 1,
    CMD_BACKWARD = 2,
    CMD_LEFT = 3,
    CMD_RIGHT = 4,
    CMD_BOW = 5,
    CMD_WAVE = 6,
    CMD_SPEED_INCREASE = 7,
    CMD_SPEED_DECREASE = 8,
    CMD_DANCE = 9,
    CMD_CENTER_SERVOS = 0,
    CMD_TRIM_LEFT = 11,
    CMD_TRIM_RIGHT = 12
};

// Create WebServer object on default http port
WebServer server(80);

void setup()
{
    // Initialize Serial communication for debugging
    Serial.begin(9600);

    // Initialize Serial2 for communication with Arduino Nano
    Serial2.begin(9600, SERIAL_8N1, 16, 17); // RX2=16, TX2=17

    // Setup WiFi Access Point
    WiFi.softAP(SSID, PASSWORD);
    IPAddress IP = WiFi.softAPIP();

    Serial.print("Access Point IP: ");
    Serial.println(IP);

    // Define server routes for all commands
    server.on("/", handleRoot);
    server.on("/stop", HTTP_GET, []()
              { sendCommand(CMD_STOP); });
    server.on("/forward", HTTP_GET, []()
              { sendCommand(CMD_FORWARD); });
    server.on("/backward", HTTP_GET, []()
              { sendCommand(CMD_BACKWARD); });
    server.on("/left", HTTP_GET, []()
              { sendCommand(CMD_LEFT); });
    server.on("/right", HTTP_GET, []()
              { sendCommand(CMD_RIGHT); });
    server.on("/bow", HTTP_GET, []()
              { sendCommand(CMD_BOW); });
    server.on("/wave", HTTP_GET, []()
              { sendCommand(CMD_WAVE); });
    server.on("/speedincrease", HTTP_GET, []()
              { sendCommand(CMD_SPEED_INCREASE); });
    server.on("/speeddecrease", HTTP_GET, []()
              { sendCommand(CMD_SPEED_DECREASE); });
    server.on("/dance", HTTP_GET, []()
              { sendCommand(CMD_DANCE); });
    server.on("/centerservos", HTTP_GET, []()
              { sendCommand(CMD_CENTER_SERVOS); });
    server.on("/trimleft", HTTP_GET, []()
              { sendCommand(CMD_TRIM_LEFT); });
    server.on("/trimright", HTTP_GET, []()
              { sendCommand(CMD_TRIM_RIGHT); });

    // Start server
    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
    server.handleClient();
}

// Send Integer Command Function with Error Handling
void sendCommand(int command)
{
    // Send command via Serial2
    Serial2.write(command); // Send as a single byte

    // Send HTTP response
    server.send(200, "text/plain", "Command sent: " + String(command));

    // Debug print
    Serial.print("Sent Command: ");
    Serial.println(command);
}

// HTML Page Handler with Press-and-Hold Functionality
void handleRoot()
{
    String html = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Quadruped Robot Control</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #f4f4f4;
            margin: 0;
            padding: 20px;
            touch-action: manipulation;
        }
        h1 { 
            color: #333; 
            margin-bottom: 50px;
        }
        .movement-container {
            display: grid;
            grid-template-columns: 1fr 1fr 1fr;
            grid-template-rows: 1fr 1fr 1fr;
            gap: 10px;
            max-width: 300px;
            margin: 0 auto 30px;
            height: 250px;
        }
        .forward { grid-column: 2; grid-row: 1; }
        .backward { grid-column: 2; grid-row: 3; }
        .left { grid-column: 1; grid-row: 2; }
        .right { grid-column: 3; grid-row: 2; }
        
        .additional-functions {
            display: grid;
            grid-template-columns: repeat(2, 1fr);
            gap: 10px;
            max-width: 400px;
            margin: 0 auto;
        }
        
        .button {
            background-color: #4CAF50;
            border: none;
            color: white;
            padding: 15px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            cursor: pointer;
            border-radius: 8px;
            transition: background-color 0.3s, transform 0.1s;
            user-select: none;
            -webkit-user-select: none;
        }
        .button:hover {
            background-color: #45a049;
            transform: scale(1.05);
        }
        .button:active {
            background-color: #3d8b40;
            transform: scale(0.95);
        }
        .movement-button {
            min-height: 60px;
        }
    </style>
</head>
<body>
    <h1>Quadruped Robot Control</h1>
    
    <div class='movement-container'>
        <button class='button movement-button forward' 
            onmousedown='startMovement("forward")' 
            onmouseup='stopMovement()' 
            onmouseleave='stopMovement()'
            ontouchstart='startMovement("forward")' 
            ontouchend='stopMovement()'
            ontouchcancel='stopMovement()'>Forward</button>
        
        <button class='button movement-button backward' 
            onmousedown='startMovement("backward")' 
            onmouseup='stopMovement()' 
            onmouseleave='stopMovement()'
            ontouchstart='startMovement("backward")' 
            ontouchend='stopMovement()'
            ontouchcancel='stopMovement()'>Backward</button>
        
        <button class='button movement-button left' 
            onmousedown='startMovement("left")' 
            onmouseup='stopMovement()' 
            onmouseleave='stopMovement()'
            ontouchstart='startMovement("left")' 
            ontouchend='stopMovement()'
            ontouchcancel='stopMovement()'>Left</button>
        
        <button class='button movement-button right' 
            onmousedown='startMovement("right")' 
            onmouseup='stopMovement()' 
            onmouseleave='stopMovement()'
            ontouchstart='startMovement("right")' 
            ontouchend='stopMovement()'
            ontouchcancel='stopMovement()'>Right</button>
    </div>
    
    <div class='additional-functions'>
        <button class='button' onclick='sendCommand("bow")'>Bow</button>
        <button class='button' onclick='sendCommand("wave")'>Wave</button>
        <button class='button' onclick='sendCommand("speedincrease")'>Increase Speed</button>
        <button class='button' onclick='sendCommand("speeddecrease")'>Decrease Speed</button>
        <button class='button' onclick='sendCommand("dance")'>Dance</button>
        <button class='button' onclick='sendCommand("centerservos")'>Center Servos</button>
        <button class='button' onclick='sendCommand("trimleft")'>Trim Left</button>
        <button class='button' onclick='sendCommand("trimright")'>Trim Right</button>
    </div>
    
    <script>
        let movementInterval = null;
        let isMoving = false;
        let lastCommand = null;
        let stopRequested = false;

        function startMovement(command) {
            // If stop was just requested, ignore new movement
            if (stopRequested) {
                stopRequested = false;
                return;
            }
            
            // Prevent multiple intervals from being started
            if (isMoving) return;
            
            isMoving = true;
            lastCommand = command;
            
            // Send initial command only once
            sendCommand(command);
            
            // Start continuous sending
            movementInterval = setInterval(() => {
                sendCommand(command);
            }, 100); // Adjust interval as needed
        }

        function stopMovement() {
            // Prevent sending multiple stop commands
            if (stopRequested) return;
            stopRequested = true;
            
            // Stop continuous sending
            if (movementInterval) {
                clearInterval(movementInterval);
                movementInterval = null;
            }
            
            // Reset the moving state
            isMoving = false;
            
            // Only send stop if there was a previous movement command
            if (lastCommand) {
                sendCommand('stop');
                lastCommand = null;
            }

            // Reset stop request after a short delay
            setTimeout(() => {
                stopRequested = false;
            }, 200);
        }

        function sendCommand(command) {
            fetch('/' + command)
                .then(response => response.text())
                .then(text => console.log(text))
                .catch(error => console.error('Error:', error));
        }
    </script>
</body>
</html>
)";

    server.send(200, "text/html", html);
}
