#include <zmq.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
	zmq::message_t message;
	zmq::context_t context(4);
	zmq::socket_t sock(context, ZMQ_PUB);
	sock.bind("tcp://*:5555");

	cv::Mat image;
	cv::VideoCapture cap(0);

	std::vector<uint8_t> buffer;
	do {
		cap >> image;

		cv::imencode(".jpg", image, buffer);

		sock.send(zmq::buffer(buffer), zmq::send_flags::none);
	} while (true);

	return -1;
}
