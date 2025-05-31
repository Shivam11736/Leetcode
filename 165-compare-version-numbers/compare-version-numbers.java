class Solution {
    public int compareVersion(String version1, String version2) {
        // 1. Split the version strings into arrays of numbers using the dot "." as a delimiter.
        //    The \\ is needed because "." is a special character in regular expressions. 
        String[] p1 = version1.split("\\."); 
        String[] p2 = version2.split("\\.");

        // 2. Determine the maximum length between the two arrays. This is needed to iterate through all parts. \U0001f4cf
        int maxLength = Math.max(p1.length, p2.length);

        // 3. Iterate through the arrays to compare the version parts one by one. \U0001f6b6‍♀️\U0001f6b6‍♂️
        for (int i = 0; i < maxLength; i++) {
            // 4. Get the integer value of the current part from p1.
            //    If the index is out of bounds (version1 has fewer parts), treat it as 0. 
            //    This prevents ArrayIndexOutOfBoundsException and handles shorter versions. 0️⃣
            Integer val1 = (i < p1.length) ? Integer.parseInt(p1[i]) : 0;

            // 5. Same as above, but for version2 (array p2).
            Integer val2 = (i < p2.length) ? Integer.parseInt(p2[i]) : 0;

            // 6. Compare the integer values of the current parts. ⚖️
            int compare = val1.compareTo(val2);

            // 7. If the parts are different, we can immediately return the comparison result.
            //    compareTo returns:
            //     -1 if val1 < val2
            //      1 if val1 > val2
            //      0 if val1 == val2 
            if (compare != 0) {
                return compare; // Return the result (1 or -1). \U0001f3c6
            }
        }

        // 8. If all parts are equal, the versions are the same. \U0001f91d
        return 0;
    }
}