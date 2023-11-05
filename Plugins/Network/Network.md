# Network.md

## Explanation of NetworkPlugin

NetworkPlugin is a CorePlugin that facilitates the initiation of a UDP session. It requires the following parameters:

- `port`
- `latency`
- `timeout`
- `user` (user identifier)

This plugin enables the establishment of a UDP session, allowing for communication between servers.

### Received Events

- `addServer`: Accepts a JSON parameter (`name`[string], `ip`[string], `port`[int]) to add a server.
- `removeServer`: Accepts a JSON parameter (`string`) to remove a server.
- `sendEvent`: Accepts a JSON parameter (`serverName`[string], `name`[string], `value`[any]) to send events to the specified server.
- `changeUser`: Accepts a JSON parameter (`string`) to change the server identifier.
- `sendAll`: Accepts a JSON parameter (`name`[string], `id`[string], `value`[any]) to broadcast the event to all servers.

### Emitted Events

- `disconnectUser`: Receives a JSON parameter (`string`) indicating the server that closed the connection.
- `newServerUser`: Receives a JSON parameter (`user`[string], `ip`[string], `port`[int]) when a new server user joins.
- All events received from the server.

For further information about plugins, please refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).

### Protocol

# Network Engine RFC (Version 1.0)

## 1. Introduction

This document outlines the design and specifications for a network engine aimed at enabling efficient communication between clients and servers. The engine employs a packet-based system with error handling and recovery mechanisms to ensure reliable data transmission.

## 2. Packet Structure

### 2.1 Client Packet

```json
{
  "id": 0,
  "user": "...",
  "events": [
    {
      "name": "event name",
      "data": {
        "name": "",
        "position": {"x": 0, "y": 0, "z": 0},
        "rotation": 0,
        "scale": {"x": 0, "y": 0, "z": 0},
        "fontName": "..."
      }
    }
  ],
  "received": [25, 26]
}
```

### 2.2 Server Packet


```json
{
  "id": 0,
  "events": [
    {
      "name": "event name",
      "data": {
        "name": "",
        "position": {"x": 0, "y": 0, "z": 0},
        "rotation": 0,
        "scale": {"x": 0, "y": 0, "z": 0},
        "fontName": "..."
      }
    }
  ],
  "received": [25, 26]
}
```

- `id`: *Packet identifier.*
- `user`: *User identifier.*
- `events`: *List of events to be executed.*
- `received`: *List of IDs of received packets.*

### 3. Operation Logic

- Users send packets to the server every `{user-defined latency}` milliseconds.
- The server sends packets to all users every `{server-defined latency}` milliseconds.
- Each packet has a unique ID ranging from 0 to 99, wrapping back to 0 infinitely.
- Both server and client maintain two arrays, each with a maximum size of 16.
- Sent packets are stored in the arrays.
- When sending a packet, users also send the received packets' IDs. If a packet has not been received, it is resent. If received, it is removed from the array.
- If an array is full, the connection is considered interrupted.

### 4. Conclusion

This network engine facilitates efficient, reliable, and real-time communication between clients and servers, ensuring seamless data transmission for various applications.

For further information about plugins, please refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).

Please note that there are no error conditions implemented. In case of a packet error, the engine will emit a message to the console and that will be the extent of the handling.
