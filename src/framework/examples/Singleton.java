
public final class Singleton {
    private static Singleton singleton=null;
    private Singleton() {}
    public static Singleton get_instance() {
        if (singleton == null)
            singleton = new Singleton();
        return singleton;
    }

    public static void main(String[] args) {
        Singleton s=get_instance();
        Singleton s2=get_instance();
        System.out.println(s == s2);
    }
}
