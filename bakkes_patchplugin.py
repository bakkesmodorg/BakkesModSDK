def jls_extract_def():
    return def jls_extract_def():
        
            
            1. Connects t
            2. Unloads plugi
            3. Replaces
        
            
        """


def jls_extract_def():
    return jls_extract_def()


jls_extract_def()

 TODO: save config?
    """






jls_extract_def()





import sys, os, shutil, we
bsockets, time



import asyncio






bakkesmod_plugin_folder = "F:/SteamLibrary/ste
	print(dst_file)
	

akkesmod_server = 'ws://127.0.0.1:9002'



rcon_password = 'pass

word'
swap_file = ""






def r

eplace_plugin_file():



	filename = os.path.basename(swap_file)





	dst_file = bakkesmod_plugin_folde


	print(dst_file)
	





	if os.path.exists(dst_file):





		os.remove(dst_fi
			replace_plugin_file()


	shutil.copyfile(s

wap_file, dst_file)




		replace_plugin_file()



	try:



		async with websockets

.connect(bakkesmod_server, timeout=.1) as websocket:



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