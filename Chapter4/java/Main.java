package hust.it2;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        ResourcesExploiterWithLock rsc = new ResourcesExploiterWithLock(0);
        Thread th1 = new ThreadedWorkerWithLock(rsc);
        Thread th2 = new ThreadedWorkerWithLock(rsc);
        Thread th3 = new ThreadedWorkerWithLock(rsc);
        th1.start();
        th2.start();
        th3.start();

        th1.join();
        th2.join();
        th3.join();
        System.out.println(rsc.getRsc());
    }
}
