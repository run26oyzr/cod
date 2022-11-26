f[0] = 0;
//f[i] = max{f[j]} + a[i]; (i - m < j < i)
for (int i = 1; i <= n; i++){
    //删队首
    while(front <= rear && q[front] + m <= i) front++;
    //取队首
    f[i] = f[q[front]] + a[i];
    //删队尾
    while(front <= rear && f[i] >= f[i] >= f[q[rear]]) rear--;
    //加队尾
    q[++rear] = i;
}