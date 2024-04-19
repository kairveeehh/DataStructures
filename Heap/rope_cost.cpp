  while(minh.size() >=2){
      int first = minh.top();
      minh.pop();
      int second = minh.top();
      minh.pop();
      tcost = tcost + first + second;
      minh.push(first + second); //push bas current length hi krenge
    }

    return cost;