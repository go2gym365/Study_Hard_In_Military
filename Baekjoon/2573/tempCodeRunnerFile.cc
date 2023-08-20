
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) vis[i][j] = false;
            glacier[i][j] -= water[i][j];
            if(glacier[i][j] < 0) glacier[i][j] = 0;
        }