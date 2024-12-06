package sem1_2.model;

import java.util.ArrayList;
import java.util.List;

public abstract class ContainerSuperclass implements Container {
    List<Task> tasks = new ArrayList<>();

    @Override
    public abstract Task remove();

    @Override
    public abstract void add(Task task);

    @Override
    public int size() {
        return tasks.size();
    }

    @Override
    public boolean isEmpty() {
        return tasks.isEmpty();
    }
}
