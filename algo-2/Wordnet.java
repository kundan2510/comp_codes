public class Wordnet{
			// constructor takes the name of the two input files
		Digraph G;
		public Wordnet(String synsets, String hypernyms)
		{
			G = new Digraph();
			String[] synlines = synsets.split(System.getProperty("line.separator"));
		}

		// the set of nouns (no duplicates), returned as an Iterable
		public Iterable<String> nouns()
		{

		}

		// is the word a WordNet noun?
		public boolean isNoun(String word)
		{

		}

		// distance between nounA and nounB (defined below)
		public int distance(String nounA, String nounB)
		{

		}

		// a synset (second field of synsets.txt) that is the common ancestor of nounA and nounB
		// in a shortest ancestral path (defined below)
		public String sap(String nounA, String nounB)
		{

		}

		public static void main(String[] args)
		{

		}
}
