/*
1010: �ÿӵĵ��ӵ�ͼ
�ύ: 667  ���: 280
- ��Ŀ����
С���ǽ���μӸ��Ե���У��������Ҫȥ����¥С����ǩ�������ڶ����ϴ�ѧУ�����ܲ���Ϥ��С���ҵ�����߶���ĺ�����³��ʦ��
���ɣ�³��ʦ��æ������̽����Ŀ�Ľ��⹤�������ܸ�����·��ֻ�ø�������һ�ݰ��Ʒ�ĵ��ӵ�ͼ��
��ͼ��ֻ�г���У�����ڵ�N���㣬M��·��С������S�㣬����¥С������T�㡣С����л³��ʦ����Ȼֻ�����õ���ͼ��һ˲�䣬
������������֪������Ʒ�����ж�ӡ�³��ʦ�����ĵ��ӵ�ͼ�Ǵ���������ʾ���ܵģ�
�����ڱ��Ϊ�����ĵ���Ҫ��1���Ӳ��ܸ�����������ô�ߣ����ڱ��Ϊż���ĵ�Ҫ��2���ӡ�
���ڸ������ͼ�ľ��������С����֪�����ܲ�����A�����ڸϵ�����¥С���á�
- ����
���������ж��飬ÿ��ռM+1�У���һ����5������N��M��S��T��A��������M�У�ÿ����������u,v,t��
����ÿ��·����������Ͳ���ʱ�䡣���������ݱ�֤�����ر�0<N<M<1000��
- ���
����ÿ���������ݣ����һ�У�С������A�����ڸϵ�����¥С�������YES�����ٻ��ѵ�ʱ�䣬�������KENG
- ��������
4 3 1 4 10
1 2 1
3 2 2
3 4 3
5 4 2 4 7
1 2 5
5 4 2
3 5 1
2 3 1
- �������
YES 10
KENG
*/

#include <iostream>
#include <limits>
#include <vector>

const int Kmax = std::numeric_limits<int>::max();

// ����src��dest���ص���̾��루����ѯ��ʱ�䣩
int Dijkstra(const std::vector<std::vector<int>>& matrix_e, const int src,
             const int dest) {
  int ask_time = src % 2 == 0 ? 1 : 2;  // �ڽӾ����Ǵ�0��ʼ����1
  if (src == dest) {
    return ask_time;  // ������յ���ͬ
  }

  // ��ʼ��
  int n = matrix_e.size();
  int final[n];
  int d[n];
  for (int v = 0; v < n; v++) {
    final[v] = 0;
    d[v] = matrix_e[src][v] == Kmax ? matrix_e[src][v]
                                    : matrix_e[src][v] + ask_time;
  }

  // ��src��ʼ�㷨
  d[src] = 0;
  final[src] = 1;
  int min;
  for (int i = 1; i < n; ++i) {
    // ������һ��
    int min_point = -1;
    min = Kmax;
    for (int w = 0; w < n; w++) {
      if (final[w] == 0 && d[w] < min) {
        min_point = w;
        min = d[w];
      }
    }
    if (min_point == -1) {
      return -1;  // ��ʣ�µĵ㲻ͨ
    }
    if (min_point == dest) {
      return d[dest];  // �յ㣬���������Բ�������
    }

    // ����S��
    final[min_point] = 1;
    // ���¾���
    ask_time = min_point % 2 == 0 ? 1 : 2;
    for (int w = 0; w < n; w++) {
      // minΪsrc��min_point��ʱ��
      // int src_to_w = min + matrix_e[min_point][w]; // ���ܳ������
      if (final[w] == 0 && matrix_e[min_point][w] != Kmax &&
          min + matrix_e[min_point][w] + ask_time < d[w]) {
        d[w] = min + matrix_e[min_point][w] + ask_time;
      }
    }
  }
  return d[dest];
}

void IsArrival(const int n, const int s, const int t, const int a,
               const std::vector<std::vector<int>>& matrix_e) {
  int res = Dijkstra(matrix_e, s - 1, t - 1);

  if (res <= a) {
    std::cout << "YES " << res << std::endl;
  } else {
    std::cout << "KENG" << std::endl;
  }
}

int main() {
  int n, m, s, t, a;
  int u, v, w;

  while (std::cin >> n >> m >> s >> t >> a) {
    // �����ڽӾ���
    std::vector<std::vector<int>> matrix_e(n, std::vector<int>(n, Kmax));
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v >> w;  // �ߵĶ�����Ȩֵ
      // ��pathת�����ڽ׾���
      matrix_e[u - 1][v - 1] = w;
      matrix_e[v - 1][u - 1] = w;
    }
    for (int i = 0; i < n; i++) {
      matrix_e[i][i] = 0;  // �Լ����Լ��ľ���
    }
    IsArrival(n, s, t, a, matrix_e);
  }

  return 0;
}
