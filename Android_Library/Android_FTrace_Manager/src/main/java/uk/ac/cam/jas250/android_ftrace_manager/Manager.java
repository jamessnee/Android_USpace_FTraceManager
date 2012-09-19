package uk.ac.cam.jas250.android_ftrace_manager;

public class Manager {
	
	private static Manager manager = null;
	
	public static Manager getManager(){
		if(manager==null)
			manager = new Manager();
		return manager;
	}
	
	private Manager(){
		
	}

}
