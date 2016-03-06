all:
	g++ -o main FrameBuffer.cpp Point.cpp Line.cpp Polygon.cpp ThreeDimension.cpp Face.cpp Curve.cpp main.cpp

run:
	./main

clean:
	rm main
