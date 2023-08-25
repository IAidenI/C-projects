using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace socket_prog
{
    class Server
    {
        static void Main(string[] args)
        {
            byte[] buffer = new byte[1000];
            string data = null;
            IPAddress ipAddress = IPAddress.Parse("192.168.0.99");
            Console.WriteLine(ipAddress);
            IPEndPoint localEndpoint = new IPEndPoint(ipAddress, 32000);
            ConsoleKeyInfo key;
            Socket sock = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            sock.Bind(localEndpoint);
            sock.Listen(5);
            while (true)
            {
                Console.WriteLine("\nWaiting for clients..");
                Socket confd = sock.Accept();
                int b = confd.Receive(buffer);
                data += Encoding.ASCII.GetString(buffer, 0, b);
                Console.WriteLine("" + data);
                data = null;
                Console.WriteLine("\nSaisir une donnee a envoyer.");
                byte[] msg = Encoding.ASCII.GetBytes(Console.ReadLine());
                confd.Send(msg);
                Console.WriteLine("\n<< Continue 'y' , Exit 'e'>>");
                key = Console.ReadKey();
                if (key.KeyChar == 'e')
                {
                    Console.WriteLine("\nExiting..Handled clients");
                    confd.Close();
                    break;
                }
                confd.Close();
            }
        }
    }
}