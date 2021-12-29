package hust.it2;

public class ThreadedWorkerWithoutSync extends Thread {
	private final ResourcesExploiter rExp;

	public ThreadedWorkerWithoutSync(ResourcesExploiter rExp) {
		this.rExp = rExp;
	}

	@Override
	public void run() {
		String name = Thread.currentThread().getName();

		for (int i = 0; i < 15; i++) {
			rExp.exploit();
			// System.out.println(name + ": " + rExp.getRsc());
		}
	}
}
