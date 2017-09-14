package com.xfhy;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/**
 * 链接：https://www.nowcoder.com/questionTerminal/9fbb4d95e6164cd9ab52e859fbe8f4ec
来源：牛客网

牛牛有N个字符串，他想将这些字符串分类，他认为两个字符串A和B属于同一类需要满足以下条件：
A中交换任意位置的两个字符，最终可以得到B，交换的次数不限。比如：abc与bca就是同一类字符串。
现在牛牛想知道这N个字符串可以分成几类。 
输入描述:

首先输入一个正整数N（1 <= N <= 50），接下来输入N个字符串，每个字符串长度不超过50。


输出描述:

输出一个整数表示分类的个数。
示例1
输入

4
abcd
abdc
dabc
bacd
输出

1

 * @author feiyang
 * 
 * 将输入的每一行的字符串排序再插入Set(唯一),那么最后查看set的大小就可以了
 * 
 */
public class StringClassification {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        HashSet<String> set = new HashSet<String>();
        while(n!=0){
            char temp[] = scan.next().toCharArray();
            Arrays.sort(temp);
            set.add(String.valueOf(temp));
            n--;
        }
        System.out.println(set.size());
	}

}
