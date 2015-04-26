/*
** ADOBE SYSTEMS INCORPORATED
** Copyright 2012 Adobe Systems Incorporated
** All Rights Reserved.
**
** NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance with the
** terms of the Adobe license agreement accompanying it.  If you have received this file from a
** source other than Adobe, then your use, modification, or distribution of it requires the prior
** written permission of Adobe.
*/
package com.adobe.flascc
{
  import flash.display.DisplayObjectContainer;
  import flash.display.Sprite;
  import flash.display.StageScaleMode;
  import flash.events.Event;
  import flash.net.LocalConnection;
  import flash.net.URLRequest;
  import flash.text.TextField;
  import flash.utils.ByteArray;

  import com.adobe.flascc.vfs.ISpecialFile;
  import com.adobe.flascc.vfs.LSOBackingStore;
  import com.adobe.flascc.vfs.RootFSBackingStore;

  /**
  * A basic implementation of a console for FlasCC apps.
  * The PlayerKernel class delegates to this for things like read/write
  * so that console output can be displayed in a TextField on the Stage.
  */
  public class Console extends Sprite implements ISpecialFile
  {
    private var inputContainer:DisplayObjectContainer

    /**
    * To Support the preloader case you might want to have the Console
    * act as a child of some other DisplayObjectContainer.
    */
    public function Console(container:DisplayObjectContainer = null)
    {
      CModule.rootSprite = container ? container.root : this

      if(container) {
        container.addChild(this)
        init(null)
      } else {
        addEventListener(Event.ADDED_TO_STAGE, init)
      }
    }

    /**
    * All of the real FlasCC init happens in this method
    * which is either run on startup or once the SWF has
    * been added to the stage.
    */
    protected function init(e:Event):void
    {
      flash.system.Security.allowDomain(sourceDomain)
      
      inputContainer = new Sprite()
      addChild(inputContainer)

      addEventListener(Event.ENTER_FRAME, enterFrame)

      stage.frameRate = 60
      stage.scaleMode = StageScaleMode.NO_SCALE

      
      // PlayerKernel will delegate read/write requests to the "/dev/tty"
      // file to the object specified with this API.
      CModule.vfs.console = this
       CModule.vfs.addDirectory("/data")
      CModule.vfs.addBackingStore(new RootFSBackingStore(), "/data")
      CModule.vfs.addDirectory("/local")
      CModule.vfs.addBackingStore(
        new LSOBackingStore("GHL-LSO"), "/local")
      CModule.startAsync(this)
    }


    /**
    * The callback to call when FlasCC code calls the posix exit() function. Leave null to exit silently.
    * @private
    */
    public var exitHook:Function;

    /**
    * The PlayerKernel implementation will use this function to handle
    * C process exit requests
    */
    public function exit(code:int):Boolean
    {
      // default to unhandled
      return exitHook ? exitHook(code) : false;
    }

    /**
    * The PlayerKernel implementation will use this function to handle
    * C IO write requests to the file "/dev/tty" (e.g. output from
    * printf will pass through this function). See the ISpecialFile
    * documentation for more information about the arguments and return value.
    */
    public function write(fd:int, bufPtr:int, nbyte:int, errnoPtr:int):int
    {
	     var str:String = CModule.readString(bufPtr, nbyte)
	     trace(str)
       if (ExternalInterface.available) 
       { 
          try 
          {
            ExternalInterface.call("logMessage",str); 
          }
       } 
      return nbyte
    }

    /**
    * The PlayerKernel implementation will use this function to handle
    * C IO read requests to the file "/dev/tty" (e.g. reads from stdin
    * will expect this function to provide the data). See the ISpecialFile
    * documentation for more information about the arguments and return value.
    */
    public function read(fd:int, bufPtr:int, nbyte:int, errnoPtr:int):int
    {
      return 0
    }

    /**
    * The PlayerKernel implementation will use this function to handle
    * C fcntl requests to the file "/dev/tty" 
    * See the ISpecialFile documentation for more information about the
    * arguments and return value.
    */
    public function fcntl(fd:int, com:int, data:int, errnoPtr:int):int
    {
      return 0
    }

    /**
    * The PlayerKernel implementation will use this function to handle
    * C ioctl requests to the file "/dev/tty" 
    * See the ISpecialFile documentation for more information about the
    * arguments and return value.
    */
    public function ioctl(fd:int, com:int, data:int, errnoPtr:int):int
    {
      return 0
    }

    
    /**
    * The enterFrame callback will be run once every frame. UI thunk requests should be handled
    * here by calling CModule.serviceUIRequests() (see CModule ASdocs for more information on the UI thunking functionality).
    */
    protected function enterFrame(e:Event):void
    {
      CModule.serviceUIRequests()
    }

    
  }
}
