#!/bin/bash
#cd /fastdata/serving

#tensorflow_model_server --port=14567 --model_name=inception --model_base_path=inception-export/ 
tensorflow_model_server --port=14568 --model_config_file=/fastdata/models_repo/models.conf
