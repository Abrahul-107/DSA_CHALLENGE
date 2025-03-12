
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

class SubsetOrNotCheck 
{

    public static boolean isSubsetOrNot(ArrayList<Integer> arr, ArrayList<Integer> arr2) 
    {
        Set<Integer> hashset = new HashSet<>();
        for (int num : arr) 
        {
            hashset.add(num);
        }

        for (int num : arr2) 
        {
            if (!hashset.contains(num)) 
            {
                return false;
            }
        }
        return true;

    }

    public static void main(String[] args) 
    {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        ArrayList<Integer> arr2 = new ArrayList<>();
        arr2.add(2);
        arr2.add(1);
        arr2.add(4);
        arr2.add(5);
        if (isSubsetOrNot(arr, arr2)) {
            System.out.println("SUBSET"); 
        }else {
            System.out.println("NOT subset");
        }
    }
}
