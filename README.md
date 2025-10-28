<h1>Mini Chat using Sockets in C</h1>

<img src="./client-server.png" alt="Client-Server Diagram">
<p>This repository contains a simple <strong>client-server chat program</strong> implemented in <strong>C</strong> using <strong>sockets</strong>.  
It demonstrates how two processes can communicate over a network using the <strong>socket API</strong>.</p>

<h2>Files</h2>
<ul>
    <li><code>server.c</code> — The server program that waits for client connections and exchanges messages.</li>
    <li><code>client.c</code> — The client program that connects to the server and sends/receives messages.</li>
</ul>

<h2>How Sockets Work</h2>
<p>A <strong>socket</strong> is an endpoint for communication between two programs, either on the same machine or over a network.  
In C, sockets allow you to send and receive data between <strong>client</strong> and <strong>server</strong> processes.</p>

<h3>Server Side</h3>
<ol>
    <li>Create a socket:
        <pre><code>int sockfd = socket(AF_INET, SOCK_STREAM, 0);</code></pre>
    </li>
    <li>Bind the socket to an IP and port:
        <pre><code>bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));</code></pre>
    </li>
    <li>Listen for incoming connections:
        <pre><code>listen(sockfd, 5);</code></pre>
    </li>
    <li>Accept a client connection:
        <pre><code>int client_sock = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);</code></pre>
    </li>
    <li>Communicate with the client using <code>send()</code> and <code>recv()</code>.</li>
</ol>

<h3>Client Side</h3>
<ol>
    <li>Create a socket:
        <pre><code>int sockfd = socket(AF_INET, SOCK_STREAM, 0);</code></pre>
    </li>
    <li>Connect to the server:
        <pre><code>connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));</code></pre>
    </li>
    <li>Communicate with the server using <code>send()</code> and <code>recv()</code>.</li>
</ol>

<h2>How to Run</h2>
<ol>
    <li><strong>Compile the programs:</strong>
        <pre><code>gcc server.c -o serve gcc client.c -o client</code></pre>
        </li>
        <li><strong>Start the server:</strong>
            <pre><code>./server</code></pre>
        </li>
        <li><strong>Start the client</strong> (in another terminal):
            <pre><code>./client</code></pre>
        </li>
        <li><strong>Start chatting:</strong> Messages typed in the client terminal will appear on the server, and vice versa.</li>
    </ol>

<h2>Notes</h2>
<ul>
    <li>Always start the server before the client.</li>
    <li>Both programs can run on the same machine (<code>localhost</code>) or on different machines via network.</li>
    <li>This is a simple demo for learning purposes; it does <strong>not include encryption or advanced error handling</strong>.</li>
</ul>
