package sem1_2.model;

public class QueueContainer extends AbstractContainer {

    @Override
    public Task remove() {
        if (!tasks.isEmpty()) {
            return tasks.remove(0);
        }
        else
            return null;
    }

    @Override
    public void add(Task task) {
        tasks.add(task);
    }

}
