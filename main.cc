#include <iostream>
#include <grpc++/grpc++.h>
#include <grpc++/security/credentials.h>
#include "pubsub.grpc.pb.h"
using namespace std;
int main()
{
	auto projectName = "projects/api-7805202409062569548-609752";
	auto channel = grpc::CreateChannel("pubsub.googleapis.com:443",
					   grpc::GoogleDefaultCredentials());
	auto stub = google::pubsub::v1::Publisher::NewStub(channel);
	google::pubsub::v1::ListTopicsRequest request;
	google::pubsub::v1::ListTopicsResponse response;
	grpc::ClientContext context;
	request.set_project(projectName);
	auto status = stub->ListTopics(&context,request,&response);
	if(status.ok())
	{
		for (const auto& topic : response.topics())
		{
			cout << topic.name() << std::endl;
		}
	}
	else
	{
		cout << status.error_message() << endl;
	}
 }
