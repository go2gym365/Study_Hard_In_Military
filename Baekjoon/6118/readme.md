1. 일반적인 다익스트라 알고리즘과 같이 로직 구성
2. 문제의 조건을 체크해야 하기 때문에 vector<int> 타입인 answer vector를 생성하여 최단거리를 가지는 노드 넣기


피드백
1. if(dist[here] < cost) continue; 값 예외처리는 while문 안에서!
2. cost에 -를 붙혀줘서 cost가 작은 값을 앞으로 오게해서 최단거리 부터 탐색하게 만들기
3. vector<int> v[50001];
   vector<int> dist(20001, INF);
   둘 차이 []는 공간을 만들어줘서 2차원배열
   ()는 공간을 초기화해줘서 1차원배열