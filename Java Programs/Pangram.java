import java.util.HashMap;
import java.util.Map;

/// Wikipedia: https://en.wikipedia.org/wiki/Pangram
public class Pangram {

	public static void main(String[] args) {
		System.out.println("Is Pangram: "+isPangram("Pangram is a sentence using every letter of alphabet at least once."));
        System.out.println("Is Pangram: "+isPangram("qwertyuiopasdfghjklzxcvbnm"));
        System.out.println("Is Pangram: "+isPangram("The quick brown fox jumps over the lazy dog"));        
    }

	// Check if a string is Pangram
    public static boolean isPangram(String s) {
    	s = s.replaceAll("[^a-zA-Z]", "").toLowerCase();
    	Map<Character, Integer> map = new HashMap<Character, Integer>();
    	for(Character ch: s.toCharArray()) {
    		if(!map.containsKey(ch)) {
    			map.put(ch, 1);
    		} else {
    			map.put(ch, map.get(ch)+1);
    		}
    	}
    	return map.size()==26;
    }
}
