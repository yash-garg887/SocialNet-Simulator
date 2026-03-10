# !/bin/bash
echo "Compiling project..."

g++ -std=c++17 -O2 AVLnodeAdjacency.cpp AVLnodePosts.cpp GraphVertex.cpp Graph.cpp SocialNet.cpp main.cpp -o main

if [ $? -eq 0 ]; then
  echo "Compilation successful!"
      echo "Running program..."
      echo "------------------------"
      ./main
  else
      echo "Compilation failed!"
  fi