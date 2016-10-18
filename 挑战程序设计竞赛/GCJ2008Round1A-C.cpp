void matrixMul(int a[][2], int b[][2]) {
  int c[2][2];
  memset(c, 0, sizeof(c));
  for(int k = 0; k < 2; ++k) {
    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
        c[i][j] += (a[i][k] * b[k][j]);
        c[i][j] %= 1000;
      }
    }
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      a[i][j] = c[i][j];
    }
  }
}

void fastMul(int a[][2], int n) {
  int c[2][2];
  c[0][0] = c[1][1] = 1;
  c[0][1] = c[1][0] = 0;
  while(n) {
    if(n & 1) {
      matrixMul(c, a);
    }
    n >>= 1, matrixMul(a, a);
  }
  printf("%03d\n", (2*c[0][0] + 1000 - 1)%1000);
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, n, cases = 1;
  gn(T);
  while(T--) {
    gn(n);
    int a[2][2];
    a[0][0] = a[1][1] = 3, a[0][1] = 5, a[1][0] = 1;
    printf("Case #%d: ", cases++);
    fastMul(a, n);
  }
  return 0;
}
