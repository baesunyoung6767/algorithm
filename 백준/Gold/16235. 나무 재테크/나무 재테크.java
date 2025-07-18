import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Main {
    public static class Tree {
        int r;
        int c;
        int age;
        boolean dead;

        public Tree(int r, int c, int age) {
            this.r = r;
            this.c = c;
            this.age = age;
            this.dead = false;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M, K;
    public static int[][] A;
    public static int[][] map;
    public static ArrayList<Tree> trees;
    public static Deque<Integer> deadTrees;
    public static int[] x = {1, -1, 0, 0, 1, 1, -1, -1};
    public static int[] y = {0, 0, 1, -1, 1, -1, -1, 1};

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);
        A = new int[N + 1][N + 1];
        map = new int[N + 1][N + 1];
        trees = new ArrayList<>();
        deadTrees = new LinkedList<>();

        for(int i = 1; i<=N; i++) {
            String[] temp = bf.readLine().split(" ");
            for(int j = 1; j<=N; j++) {
                A[i][j] = Integer.parseInt(temp[j - 1]);
                map[i][j] = 5;
            }
        }

        for(int i = 0; i<M; i++) {
            String[] tree = bf.readLine().split(" ");
            int x = Integer.parseInt(tree[0]);
            int y = Integer.parseInt(tree[1]);
            int z = Integer.parseInt(tree[2]);

            trees.add(new Tree(x, y, z));
        }

        Collections.sort(trees, (t1, t2) -> t1.age - t2.age);

        for(int t = 0; t<K; t++) {
            // 1.
            for(int i = 0; i<trees.size(); i++) {
                Tree tree = trees.get(i);
                if(map[tree.r][tree.c] >= tree.age) {
                    map[tree.r][tree.c] -= tree.age;
                    tree.age++;
                } else {
                    deadTrees.add(i);
                }
            }

            // 2. 
            while(!deadTrees.isEmpty()) {
                int treeIdx = deadTrees.pollLast();
                Tree deadTree = trees.get(treeIdx);
                int addAge = deadTree.age / 2;
                map[deadTree.r][deadTree.c] += addAge;
                deadTree.dead = true;
            }

            // 3.
            ArrayList<Tree> newTrees = new ArrayList<>();
            for(int i = 0; i<trees.size(); i++) {
                Tree tree = trees.get(i);

                if(tree.dead) continue;

                if(tree.age % 5 == 0) {
                    for(int j = 0; j<8; j++) {
                        int nx = tree.r + x[j];
                        int ny = tree.c + y[j];

                        if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

                        newTrees.add(new Tree(nx, ny, 1));
                    }
                }                
            }

            for(int i = 0; i<trees.size(); i++) {
                Tree tree = trees.get(i);
                if(!tree.dead) newTrees.add(tree);
            }

            trees = newTrees;

            // 4.
            for(int i = 1; i<=N; i++) {
                for(int j = 1; j<=N; j++) {
                    map[i][j] += A[i][j];
                }
            }
        }

        int result = 0;
        for(int i = 0; i<trees.size(); i++) {
            Tree tree = trees.get(i);
            if(!tree.dead) {
                result++;
            }
        }
        System.out.println(result);
    }
}
