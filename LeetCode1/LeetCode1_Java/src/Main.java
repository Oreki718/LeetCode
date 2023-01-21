import java.util.Arrays;
import java.util.HashMap;

public class Main {

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i=0;i<nums.length;i++){
            if (map.containsKey(target-nums[i])){
                return new int[] {map.get(target-nums[i]), i};
            }else{
                map.put(nums[i], i);
            }
        }
        return null;
    }
    public static void main(String[] args) {
        int[] nums = new int[] {1,2,3,4,5,6};
        int target = 5;
        int[] answ = twoSum(nums, target);
        System.out.println(Arrays.toString(answ));
    }
}