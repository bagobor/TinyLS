### TinyLoomScript (WIP)

An extremely lean stack for embedding LoomScript

Compiles on OSX currently and generates tinylsc (compiler) and tinyrun (executes a Main.loom with a static main entry point)

For example:

```as3
package
{
    // force a reference to system package for linker
    // we should not need to do this and it will be fixed
    import system.Math;

    public class HelloTinyLoomScript
    {
        public static function main()
        {
            trace("Hello from TinyLoomScript!");

            var pi = Math.PI;

            trace("PI is", pi);
        }
    }

}
```

For more information please see: http://www.LoomSDK.com
