

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class statistics{
	static int countCmp1;
	static int countCmp2;
	static int countEquals;
	static int countFindComm;
	static long timeStart;
}

class yezi{
	String yezi;	// 叶子结点字符
	List list;		// 叶子结点到顶点的链表
	yezi(String yezi, List list){
		this.yezi = yezi;
		this.list = list;
	}
}

class bian{
	String start;	//开始结点
	String end;		//结束结点
	int num;		//访问次数
	
	bian(String start, String end){
		this.start = start;
		this.end = end;
		this.num = 0;
	}
	
	boolean equals(bian b){
		statistics.countEquals++;
		if(this.start.equals(b.start) && this.end.equals(b.end)){
			return true;
		}
		return false;
	}
}
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k,i,j;
		String result="";	// 保存最后的输出结果
		String[] strarr;	
		
		while(sc.hasNext()){
			statistics.countCmp1=0;
			statistics.countCmp2=0;
			statistics.countEquals=0;
			statistics.countFindComm=0;
			statistics.timeStart=System.currentTimeMillis();
			result = "";
			k = Integer.parseInt(sc.nextLine());	// 获取节点数
			bian[] barr = new bian[k-1];			// 建立k-1条边的数组
			
			for(i=0; i<k-1; i++){					// 获取k-1条边
				strarr = sc.nextLine().split(" ");
				barr[i] = new bian(strarr[0], strarr[1]);	//初始化边数组元素
			}
			
			strarr = sc.nextLine().split(" ");	// 获取叶子结点串
			yezi[] yarr = new yezi[strarr.length];	
			
			//初始化叶子结点数组元素，创建叶子结点到顶点的链表
			for(i=0; i<strarr.length; i++){
				List list = new ArrayList();
				String strtemp = strarr[i];
				while(!strtemp.equals("1")){	// 因为顶点默认为1
					list.add(strtemp);
					strtemp = cmp(barr, strtemp); // 已知end结点找到对应的start结点
				}
				list.add(strtemp);
				yarr[i] = new yezi(strarr[i],list);
			}
			
			// 计算顶点到第一个叶子结点的路径
			List ltemp = yarr[0].list;
			for(i=ltemp.size()-1; i>=0; i--){
				result = result + ltemp.get(i)+" ";
				if(i!=0){
					bian btemp = new bian((String)ltemp.get(i), (String)ltemp.get(i-1));
					++barr[cmp1(barr,btemp)].num;
				}
			}
			
			// 计算前一个叶子结点到后一个叶子结点的路径
			for(i = 0; i < yarr.length-1; i++){
				// 寻找两个叶子链表中距离最近的一个公共父节点，并返回父节点在在两个链表中的位置
				// fr[0]保存公共父节点在前一个叶子链表中的位置
				// fr[1]保存公共父节点在后一个叶子链表中的位置
				int[] fr = firstsame(yarr[i].list, yarr[i+1].list);
				//计算前一个叶子结点到公共父节点的路径
				ltemp = yarr[i].list;
				for(j=0; j<fr[0]; j++){
					result = result + ltemp.get(j+1)+" ";	// 把结点保存到结果中
					bian btemp = new bian((String)ltemp.get(j+1), (String)ltemp.get(j));	// 当前访问的边
					if(++barr[cmp1(barr,btemp)].num > 2){ // 对当前访问边的访问次数加1，当访问次数大于2时，置结果为-1
						result = "-1";
						break;
					}
				}
				if(j!=fr[0]){
					break;
				}
				//计算公共父节点到后一个叶子结点的路径
				ltemp = yarr[i+1].list;
				for(j=fr[1]; j>0; j--){
					result = result + ltemp.get(j-1)+" ";	// 把结点保存到结果中
					bian btemp = new bian((String)ltemp.get(j), (String)ltemp.get(j-1));	// 当前访问的边
					if(++barr[cmp1(barr,btemp)].num > 2){ // 对当前访问边的访问次数加1，当访问次数大于2时，置结果为-1
						result = "-1";
						break;
					}
				}
				if(j!=0){
					break;
				}
			}
			
			//计算最后一个叶子结点到顶点的路径
			if(i == yarr.length-1){
				ltemp = yarr[i].list;
				for(i=1; i<ltemp.size()-1; i++){
					result = result + ltemp.get(i) + " ";
					bian btemp = new bian((String)ltemp.get(i),(String)ltemp.get(i-1));
					if(++barr[cmp1(barr,btemp)].num > 2){
						result = "-1";
						break;
					}
				}
				if(i == ltemp.size()-1){
					result = result + ltemp.get(ltemp.size()-1);
				}
			}
			System.out.println(result);
			System.out.println("cmp被调用次数："+ statistics.countCmp1);
			System.out.println("cmp1被调用次数："+ statistics.countCmp2);
			System.out.println("equals被调用次数：" + statistics.countEquals);
			System.out.println("firstsame被调用次数：" + statistics.countFindComm);
			System.out.println("执行时间：" + (System.currentTimeMillis()-statistics.timeStart)+ "ms");
			
		}
	}
	
	// 已知end结点找到对应的start结点
	static String cmp(bian[] barr, String str){
		for(int i = 0; i < barr.length; i++){
			statistics.countCmp1++;
			if(str.equals(barr[i].end)){
				return barr[i].start;
			}
		}
		return null;
	}

	// 在边数组中寻找某一条边，并返回它的位置
	static int cmp1(bian[] barr, bian btemp){
		for(int i = 0; i < barr.length; i++){
			statistics.countCmp2++;
			if(btemp.equals(barr[i])){
				return i;
			}
		}
		return 0;
	}
	
	// 寻找连个叶子结点到顶点的链中距离最近的一个公共父节点，并返回父节点在在两个链表中的位置
	static int[] firstsame(List a, List b){
		for(int i = 1; i < a.size(); i++){
			for(int j = 1; j < b.size(); j++){
				statistics.countFindComm++;
				if(((String)a.get(i)).equals((String)b.get(j))){
					return new int[]{i,j};
				}
			}
		}
		return null;
	}
}
