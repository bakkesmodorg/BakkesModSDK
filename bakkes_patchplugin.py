"""Script to hotswap plugin from bakkesmod process.

1. Connects to BakkesMod rcon
2. Unloads plugin
3. Replaces DLL file
4. Loads plugin

TODO: save config?
"""
import sys, os, shutil, websockets, time
import asyncio

bakkesmod_plugin_folder = "F:/SteamLibrary/steamapps/common/rocketleague/Binaries/Win32/bakkesmod/plugins/"
bakkesmod_server = 'ws://127.0.0.1:9002'
rcon_password = 'password'
swap_file = ""

def replace_plugin_file():
	filename = os.path.basename(swap_file)
	dst_file = bakkesmod_plugin_folder + filename
	print(dst_file)
	
	if os.path.exists(dst_file):
		os.remove(dst_file)
	shutil.copyfile(swap_file, dst_file)

async def main_loop():
	try:
		async with websockets.connect(bakkesmod_server, timeout=.1) as websocket:
			await websocket.send('rcon_password ' + rcon_password)
			auth_status = await websocket.recv()
			assert auth_status == 'authyes'

			filename = os.path.basename(swap_file)
			plugin_name = filename[0:filename.index('.')]
			print("Copying " + filename + "")
			await websocket.send("plugin unload " + plugin_name)
			time.sleep(0.1)
			replace_plugin_file()
			time.sleep(0.1)
			await websocket.send("plugin load " + plugin_name)
	except:
		replace_plugin_file()


if __name__ == '__main__':
	if len(sys.argv) == 1:
		exit()

	swap_file = sys.argv[1]
	asyncio.get_event_loop().run_until_complete(main_loop())