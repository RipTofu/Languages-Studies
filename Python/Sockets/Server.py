import socket

HOST = "127.0.0.1"
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    print("esperando...")
    s.listen()
    print("s.listen ejecutado")
    conn, addr = s.accept()
    print("conexion aceptada")
    with conn: # Segundo socket: socket de conexión.
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)