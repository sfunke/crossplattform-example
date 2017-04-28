//
//  ViewController.swift
//  CrossExample
//
//  Created by Steffen Funke on 27.04.17.
//  Copyright © 2017 Steffen Funke. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var myLabel: UILabel!
    @IBOutlet weak var imageView: UIImageView!
    var wrapper:CPlusPlusWrapper?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        myLabel.text = CPlusPlusWrapper.getCppString("Swift")
        wrapper = CPlusPlusWrapper(imageView: imageView)
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.0, execute: {
            self.wrapper?.start()
        })
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

