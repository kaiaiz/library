/*单例设计模式
如果一个类始终只能创建一个实例，则这个类被称为单例类。
根据良好封装的原则：一旦将该类隐藏起来，则需要提供一个public方法作为该类得访问点，用于创建该类的实例，我们把该类得构造器用private修饰，从而把该类的所有构造器隐藏起来。因此需要提供一个public方法作为该类的访问点，用于创建该类的对象。除此之外，该类还必须使用一个属性来保存曾经创建的对象，因为该属性需要被上面静态方法访问，故该属性必须使用static修饰。*/
//this is for JAVA
class Singleton{
private static Singleton instance;
private static Singleton getInstance(){
if(instance==null)
instance=new Singleton();
}
}
public calss TestSingleton{
public static void main(String[] args){
Single s1=new Singleton.getInstance();
Single s2=new Singleton.getInstance();
System.out.println(s1==s2);
}
}
