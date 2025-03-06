
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class TestHelloWorld {
    private Hello hello;
    
    @Before
    public void setUp() {
        hello = new Hello();
    }
    
    @Test
    public void test_default_message() {
        assertEquals(hello.message(), "Hello, World");
    }

    @Test
    public void test_custom_message() {
        assertEquals(hello.message("Bob"), "Hello, Bob");
    }
}
