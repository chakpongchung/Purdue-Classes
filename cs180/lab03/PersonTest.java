import junit.framework.TestCase;
/**
 * CS180 - Lab 03 - PersonTest.java
 * 
 * A test class for Person.java
 * 
 * @author Joel Van Auken <jvanauke@purdue.edu>
 *
 * @lab 807
 *
 * @date 9/18/2014
 */

public class PersonTest extends TestCase {
 
    private Person adult_badTC;
    private Person child_goodHDL;
    private Person adult_badLDL;
    
    protected void setUp() throws Exception {
        super.setUp();
        adult_badTC = new Person("01", 21, 100, 100, 100);
        child_goodHDL = new Person("02", 17, 300, 300, 300);
        adult_badLDL = new Person("03", 18, 20, 20, 20);
    }
    
    public void testGetTotalCholesterol() {
        assertEquals(300, adult_badTC.getTotalCholesterol());
    }
    public void testHasGoodTotalCholesterol() {
        assertFalse(adult_badTC.hasGoodTotalCholesterol()); 
    }
    public void testHasGoodLDL() {
        assertTrue(adult_badTC.hasGoodLDL()); 
    }
    public void testHasGoodHDL() { 
        assertTrue(adult_badTC.hasGoodHDL()); 
    }
    
}