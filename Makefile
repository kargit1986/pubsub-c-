All:
	g++ main.cc pubsub.pb.cc pubsub.grpc.pb.cc  -o pubsub  -I/home/vagrant/tests/googleapis/gens  -std=c++14 -Wl,-lgrpc -lgrpc++    -lprotobuf
