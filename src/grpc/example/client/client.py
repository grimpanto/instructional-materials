
import grpc

import greeter_pb2
import greeter_pb2_grpc

def run():
  channel = grpc.insecure_channel('localhost:8888')
  stub = greeter_pb2_grpc.GreeterStub(channel)
  response = stub.say_hello(greeter_pb2.HelloRequest(name='Maxi'))
  print("Greeter client received: " + response.message)

run()
