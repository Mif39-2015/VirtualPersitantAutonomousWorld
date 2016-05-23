using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class GraphicsManager : MonoBehaviour {

    public new GameObject light;
    public Transform shadowDropdown;
    public Transform aaDropdown;
    public Transform aniFilDropdown;
    public Transform resolutionDropDown;
    public Transform screenDropdown;
    public Transform qualityDropdown;
    int width;
    int height;
    bool screenMode;

    void Start()
    {
        QualitySettings.SetQualityLevel(5, true);
        width = 640;
        height = 480;
        screenMode = true;
        SetScreenResolution(width, height, screenMode);
    }
	
	// Update is called once per frame
	void Update () {

        //Quality level
        //SetQualityLevel();

        //Shadows
        SetShadows();

        //AntiAliasing
        SetAntialiasing();

        //Anisotropic filtering setting
        SetAnisotropic();

        //Resolution
        SetResolution();

        //Screen Mode
        SetScreenMode();

        //Screen resolution
        SetScreenResolution(width, height, screenMode);
    }

    //Set the Shadows
    public void SetShadows()
    {
        if (shadowDropdown.GetComponent<Dropdown>().value == 0)
            light.GetComponent<Light>().shadows = LightShadows.None;
        else if (shadowDropdown.GetComponent<Dropdown>().value == 1)
            light.GetComponent<Light>().shadows = LightShadows.Hard;
        else if (shadowDropdown.GetComponent<Dropdown>().value == 2)
            light.GetComponent<Light>().shadows = LightShadows.Soft;
    }

    //Set the Aliasing
    public void SetAntialiasing()
    {
        if (aaDropdown.GetComponent<Dropdown>().value == 0)
            QualitySettings.antiAliasing = 0;
        else if (aaDropdown.GetComponent<Dropdown>().value == 1)
            QualitySettings.antiAliasing = 2;
        else if (aaDropdown.GetComponent<Dropdown>().value == 2)
            QualitySettings.antiAliasing = 4;
        else if (aaDropdown.GetComponent<Dropdown>().value == 3)
            QualitySettings.antiAliasing = 8;
    }

    //Set the Anisotropic filtering
    public void SetAnisotropic()
    {
        if (aniFilDropdown.GetComponent<Dropdown>().value == 0)
            QualitySettings.anisotropicFiltering = AnisotropicFiltering.Disable;
        else if (aniFilDropdown.GetComponent<Dropdown>().value == 1)
            QualitySettings.anisotropicFiltering = AnisotropicFiltering.Enable;
        else if (aniFilDropdown.GetComponent<Dropdown>().value == 2)
            QualitySettings.anisotropicFiltering = AnisotropicFiltering.ForceEnable;
    }

    //Set the resolution
    public void SetResolution()
    {
        if (resolutionDropDown.GetComponent<Dropdown>().value == 0)
        {
            width = 640;
            height = 480;
        }
        else if (resolutionDropDown.GetComponent<Dropdown>().value == 1)
        {
            width = 800;
            height = 600;
        }
        else if (resolutionDropDown.GetComponent<Dropdown>().value == 2)
        {
            width = 1024;
            height = 768;
        }
        else if (resolutionDropDown.GetComponent<Dropdown>().value == 3)
        {
            width = 1600;
            height = 1200;
        }
        else if (resolutionDropDown.GetComponent<Dropdown>().value == 4)
        {
            width = 1920;
            height = 1080;
        }
    }

    //Set the screen mode
    public void SetScreenMode()
    {
        if (screenDropdown.GetComponent<Dropdown>().value == 0)
            screenMode = true;
        else if (screenDropdown.GetComponent<Dropdown>().value == 1)
            screenMode = false;
    }

    //Set the quality level
    public void SetQualityLevel()
    {
        //Set the quality level
        if (qualityDropdown.GetComponent<Dropdown>().value == 0)
            QualitySettings.SetQualityLevel(0, true);
        else if (qualityDropdown.GetComponent<Dropdown>().value == 1)
            QualitySettings.SetQualityLevel(1, true);
        else if (qualityDropdown.GetComponent<Dropdown>().value == 2)
            QualitySettings.SetQualityLevel(2, true);
        else if (qualityDropdown.GetComponent<Dropdown>().value == 3)
            QualitySettings.SetQualityLevel(3, true);
        else if (qualityDropdown.GetComponent<Dropdown>().value == 4)
            QualitySettings.SetQualityLevel(4, true);
        else if (qualityDropdown.GetComponent<Dropdown>().value == 5)
            QualitySettings.SetQualityLevel(5, true);

        //Upgrade the dropdowns after the quality level setting
        if (QualitySettings.GetQualityLevel() == 0 || QualitySettings.GetQualityLevel() == 1 || QualitySettings.GetQualityLevel() == 2) //very low, low, normal
            aaDropdown.GetComponent<Dropdown>().value = 0;
        else if (QualitySettings.GetQualityLevel() == 3) //High
            aaDropdown.GetComponent<Dropdown>().value = 1;
        else if (QualitySettings.GetQualityLevel() == 4) //Very High
            aaDropdown.GetComponent<Dropdown>().value = 2;
        else if (QualitySettings.GetQualityLevel() == 5) //Ultra
            aaDropdown.GetComponent<Dropdown>().value = 3;

        if (QualitySettings.GetQualityLevel() == 0 || QualitySettings.GetQualityLevel() == 1) //very low, low
            shadowDropdown.GetComponent<Dropdown>().value = 0;
        else if (QualitySettings.GetQualityLevel() == 2 || QualitySettings.GetQualityLevel() == 3) //Normal, High
            shadowDropdown.GetComponent<Dropdown>().value = 1;
        else if (QualitySettings.GetQualityLevel() == 4 ||QualitySettings.GetQualityLevel() == 5) //Very High, ultra
            shadowDropdown.GetComponent<Dropdown>().value = 2;
        //shadowDropdown.GetComponent<Dropdown>().value = QualitySettings.GetQualityLevel() / 2;


        if (QualitySettings.GetQualityLevel() == 0 || QualitySettings.GetQualityLevel() == 1) //very low, low
            aaDropdown.GetComponent<Dropdown>().value = 0;
        else if (QualitySettings.GetQualityLevel() == 2 || QualitySettings.GetQualityLevel() == 3) //Normal, High
            aaDropdown.GetComponent<Dropdown>().value = 1;
        else if (QualitySettings.GetQualityLevel() == 4 || QualitySettings.GetQualityLevel() == 5) //Very High, ultra
            aaDropdown.GetComponent<Dropdown>().value = 2;
        //aaDropdown.GetComponent<Dropdown>().value = QualitySettings.GetQualityLevel() / 2;
    }

    //Enable/Disable the popups
    public void TogglePopup(bool newValue)
    {
        //TODO
    }

    //Enable/Disable the triple buffering
    public void ToggleTripleBuff(bool newValue)
    {
        if (newValue)
            QualitySettings.maxQueuedFrames = 3;
        else
            QualitySettings.maxQueuedFrames = 0;
    }   

    //Enable/disable the vsync
    public void ToggleVsync(bool newValue)
    {
        if (newValue)
            QualitySettings.vSyncCount = 1;
        else
            QualitySettings.vSyncCount = 0;
    }

    //Set the screen resolution
    public void SetScreenResolution(int width, int height, bool screen)
    {
        Screen.SetResolution(width, height, screen);
    }
}

