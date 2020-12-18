#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2\opencv.hpp>
#include <WS2tcpip.h>


// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

// Saves us from typing std::cout << etc. etc. etc.
using namespace std;
using namespace cv;

int main(int argc, char* argv[]) // We can pass in a command line option!! 
{


#pragma region comments
	// Structure to store the WinSock version. This is filled in
// on the call to WSAStartup()  
#pragma endregion

	WSADATA data;

#pragma region comments
	// To start WinSock, the required version must be passed to
// WSAStartup(). This server is going to use WinSock version
// 2 so I create a word that will store 2 and 2 in hex i.e.
// 0x0202  
#pragma endregion

	WORD version = MAKEWORD(2, 2);

	// Start WinSock
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		// Not ok! Get out quickly
		cout << "Can't start Winsock! " << wsOk;
		return -1;
	}

	#pragma region Comments
	////////////////////////////////////////////////////////////
// CONNECT TO THE SERVER
////////////////////////////////////////////////////////////

// Create a hint structure for the server  
#pragma endregion

	sockaddr_in server;
	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(54000); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Convert from string to byte array

													   
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);	   // Socket creation, note that the socket type is datagram


	VideoCapture cap("OpenCV1.mp4"); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}


	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

	while (1)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) // Unsuccessfull read proces
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat grayscale;
		cvtColor(frame, grayscale, CV_RGB2GRAY);

		int counter = 0;

		for ( int i = 0; i < grayscale.rows; i++)
		{
			for (int j = 0; j < grayscale.cols; j++)
			{
				if (grayscale.at<uchar>(i,j)>=100 && grayscale.at<uchar>(i, j)<=150)
				{
					counter++;
				}
			}
		}

		string s= to_string(counter);
		int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));

		if (sendOk == SOCKET_ERROR)
		{
			cout << "That didn't work! " << WSAGetLastError() << endl;
		}

		cout << counter << endl;


		imshow("MyVideo", grayscale);

		if (waitKey(30) == 27)
		{
			cout << "Esc key is pressed by user" << endl;
			break;
		}
	}

	#pragma region Comments
	////////////////////////////////////////////////////////////
// INITIALIZE WINSOCK
////////////////////////////////////////////////////////////


// Write out to that socket


// Close down Winsock  
#pragma endregion

	WSACleanup();
	return 0;
}