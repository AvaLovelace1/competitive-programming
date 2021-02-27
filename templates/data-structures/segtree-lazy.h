int N, Q, h;
int arr[MAX], tree[2 * MAX], lazy[MAX], size[MAX];

void build() {
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1] = arr[i];
        size[i + N - 1] = 1;
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
        size[i] = size[i << 1] + size[i << 1 | 1];
    }
}

void apply(int pos, int x) {
    tree[pos] += x * size[pos];
    if (pos < N) {
        lazy[pos] += x;
    }
}

void up(int pos) {
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1] + lazy[i] * size[i];
    }
}

void down(int pos) {
    for (int s = h; s > 0; s--) {
        int i = pos >> s;
        if (lazy[i]) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

// without lazy propagation
void update(int pos, int x) {
    pos += N - 1;
    tree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

// with lazy propagation
void update(int l, int r, int x) {
    l += N - 1, r += N - 1;
    int l0 = l, r0 = r;
    //For operations such as assignment, the changes have to be pushed down before making new changes
    //down(l0), down(r0);
    while (l <= r) {
        if (l & 1) {
            apply(l, x);
            l++;
        }
        if (!(r & 1)) {
            apply(r, x);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    up(l0), up(r0);
}

int query(int l, int r) {
    l += N - 1, r += N - 1;
    down(l), down(r);
    int sum = 0;
    while (l <= r) {
        if (l & 1) {
            sum += tree[l];
            l++;
        }
        if (!(r & 1)) {
            sum += tree[r];
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return sum;
}

int main() {
    
    scanf("%d", &N);
    h = sizeof(int) * 8 - __builtin_clz(N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    build();
    
    scanf("%d", &Q);
    char c;
    int a, b, x;
    while (Q--) {
        scanf(" %c", &c);
        if (c == 'U') {
            scanf("%d%d%d", &a, &b, &x);
            update(a, b, x);
        } else if (c == 'Q') {
            scanf("%d%d", &a, &b);
            printf("Sum from %d to %d: %d\n", a, b, query(a, b));
        }
    }
    
    return 0;
    
}
