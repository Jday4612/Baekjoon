#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int line[1001][1001] = { 0 }, visited_D[1001] = { 0 }, visited_B[1001] = { 0 }, queue[1001];
void DFS(int N, int V);
void BFS(int N, int V);

int main() {
    int N, M, V, tmp1, tmp2;

    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        line[tmp1][tmp2] = 1;
        line[tmp2][tmp1] = 1;
    }

    DFS(N, V);
    printf("\n");
    BFS(N, V);

    return 0;
}

void DFS(int N, int V) {
    visited_D[V] = 1;
    printf("%d ", V);

    for (int i = 1; i <= N; i++) {
        if (visited_D[i] == 0 && line[V][i] == 1) {
            DFS(N, i);
        }
    }
}

void BFS(int N, int V) {
    int front = -1, back = 0, criteria;

    printf("%d ", V);
    visited_B[V] = 1;
    queue[back] = V;

    while (front < back) {
        criteria = queue[++front];
        for (int i = 1; i <= N; i++) {
            if (visited_B[i] == 0 && line[criteria][i] == 1) {
                printf("%d ", i);
                visited_B[i] = 1;
                queue[++back] = i;
            }
        }
    }
}