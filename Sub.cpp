#include <opencv2/opencv.hpp>
#include <zmq.hpp>

int main(int argc, char *argv[])
{
	zmq::message_t message;
	zmq::context_t context(1);
	zmq::socket_t sock(context, ZMQ_SUB);
	sock.set(zmq::sockopt::subscribe, "");
	sock.connect("tcp://127.0.0.1:5555");

	do {
		sock.recv(message, zmq::recv_flags::none);

		std::vector<uint8_t> jpeg(
			static_cast<uint8_t *>(message.data()),
			static_cast<uint8_t *>((uint8_t *) message.data() + message.size()));
		cv::Mat image = cv::imdecode(jpeg, cv::IMREAD_COLOR);

		cv::imshow("Sample", image);
		cv::waitKey(10);
	} while (true);

	return -1;
}
