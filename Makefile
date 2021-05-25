build-and-execute:
	bazel build --cxxopt='-std=c++17' fractals
	./bazel-bin/fractals
