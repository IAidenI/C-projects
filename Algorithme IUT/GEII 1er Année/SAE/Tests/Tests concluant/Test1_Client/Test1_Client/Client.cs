using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;


namespace socket_prog
{
    class Client
    {
        private static void Main(String[] args)
        {
            ConsoleKeyInfo key;
            byte[] data = new byte[10];
            //IPHostEntry iphostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAdress = IPAddress.Parse("192.168.0.99");//iphostInfo.AddressList[0];
            IPEndPoint ipEndpoint = new IPEndPoint(ipAdress, 32000);

            while (true)
            {
                Socket client = new Socket(ipAdress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);


                client.Connect(ipEndpoint);

                Console.WriteLine("Socket created to {0}", client.RemoteEndPoint.ToString());

                Console.WriteLine("\nSaisir une donnee a envoyer.");
                byte[] sendmsg = Encoding.ASCII.GetBytes(Console.ReadLine());

                int n = client.Send(sendmsg);

                int m = client.Receive(data);

                Console.WriteLine("" + Encoding.ASCII.GetString(data));
                client.Shutdown(SocketShutdown.Both);

                Console.WriteLine("\n<< Continue 'y' , Exit 'e'>>");
                key = Console.ReadKey();
                if (key.KeyChar == 'e')
                {
                    client.Close();
                    break;
                }
            }

            Console.WriteLine("Transmission end.");

        }
    }
}