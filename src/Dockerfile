FROM gcc:latest

WORKDIR /app
COPY . .

# Install required dependencies
RUN apt-get update && \
    apt-get install -y cmake make

# Build the application
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

EXPOSE 8080

CMD ["./build/os"]
