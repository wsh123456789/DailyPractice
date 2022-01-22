import java.util.Arrays;

/*
    此案例可以得出 int[] 数组名2 = 数组名1，是吧数组1的栈地址赋值给了数组2，和c中的指针类似，则arr[数值]的值存在堆中
    静态初始化格式为：
        int[] arr = new int[]{1,2,3};
        int[] arr = {1,2,3};
*/
import java.util.Scanner;
public class ArrayDemo {
    public static void main(String[] args) {
/*        int[] arr = new int[3];
        arr[0]  = 100;
        arr[1]  = 200;
        arr[2]  = 300;
        System.out.println(arr);
        System.out.println(arr[0]);
        System.out.println(arr[1]);
        System.out.println(arr[2]);

        int[] arr2 = arr;
        arr2[0] = 111;
        arr2[1] = 222;
        arr2[2] = 333;
        System.out.println(arr);
        System.out.println(arr[0]);//  111
        System.out.println(arr2);
        System.out.println(arr2[0]);// 111*/
        //输入十个数，求最大值
        int[] arr = new int[1000];
        int max = -0xEE;
        Scanner sc = new Scanner(System.in);
        for(int i = 0 ; i < 10 ; i++){
            arr[i] = sc.nextInt();
            if(arr[i] > max){
                max = arr[i];
            }
        }
        System.out.println(max+"为最大值");

    }
}
