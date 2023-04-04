module goproto

go 1.15

replace google.golang.org/grpc => github.com/grpc/grpc-go v1.35.0

require (
	github.com/docker/docker v20.10.24+incompatible
	google.golang.org/grpc v1.27.0
	google.golang.org/protobuf v1.25.0
)
