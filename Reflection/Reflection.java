
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

class Reflection{
	public static void main(String[] args){
		RoleFactory factory = new RoleFactory();
		String shortName = "SpiderMan";
		Role p = factory.createRole(shortName);
		if(p!=null)
			p.say();
		else
			System.out.println("无法找到 \'" + shortName + "\' 的对应类!");
	}
}

interface Role{
		public void say();
	}
class IronMan implements Role{
	@Override
	public void say(){
		System.out.println("I am IronMan!");
	}
}
class SpiderMan implements Role{
	@Override
	public void say(){
		System.out.println("I am SpiderMan!");
	}
}

//person工厂
class RoleFactory{
	//简单工厂模式
	// public Role createRole(String name){
	// 	Role role = null;
	// 	if(name.equals("IronMan"))
	// 		role = new IronMan();
	// 	else if(name.equals("SpiderMan"))
	// 		role = new SpiderMan();
	// 	return role;
	// }

	//反射机制
	public static Properties init(){
		Properties propertes = new Properties();
		try{
			propertes.load(new FileInputStream("NameMapping.properties"));
		}catch(IOException e){
			e.printStackTrace();
		}
		return propertes;
	}

	public Role createRole(String shortName){
		Role role = null;
		try{
			String fullName = init().getProperty(shortName);
			System.out.println("fullName:" + fullName);
			role = (Role)Class.forName(fullName).newInstance();
		}catch(Exception e){
			e.printStackTrace();
		}
		return role;
	}
}
