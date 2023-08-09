
    ret = 0;
    
    ret += solve(sum + vec[cnt], cnt + 1);
    ret += solve(sum - vec[cnt], cnt + 1);

    return ret;